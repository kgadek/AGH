#ifndef _BITVECTOR_KG
#define _BITVECTOR_KG

typedef unsigned int uint;
typedef unsigned char uchar;

namespace kpfp {

/**
  * Wektor bitowy.
  *
  * Zajmuje \f$8A\left\lceil\frac{z}{8A}\right\rceil+3\cdot B + C\f$ bajtow, gdzie
  *  - \f$  A  \f$ - rozmiar typu ,,unsigned char'' (zwykle 1 bajt),
  *  - \f$  B  \f$ - rozmiar typu ,,unsigned int'' (4 bajty),
  *  - \f$  C  \f$ - rozmiar wskaznika na ,,unsigned int'' (4 bajty).
  */
class bitvector {
    /**
      * Wskaźnik na dane.
      */
    uchar *p;
    /**
      * Ilosc przechowywanych danych.
      */
    uint s;
    /**
      * Rozmiar zaalokowanej przestrzeni.
      * Zawsze zachodzi \f$ 8As \leq z \f$.
      */
    uint z;
    /**
      * Skok rozmiaru alokowanej pamięci.
      * Zmiana rozmiaru w górę \f$ \iff \f$ nie ma już miejsca na nowy element,
      */
    uint r;
public:
    /**
      * Konstruktor alokujący zadaną ilość miejsca.
      * @param _s Ilość bajtów do zarezerwowania. Zaalokowanych zostanie
      * \f$ 8A\left\lceil\frac{\_ s}{8A}\right\rceil \f$ bajtów.
      * @param _r Skok rozmiaru alokowanej pamięci.
      */
    bitvector(uint _s=0, uint _r=25) : p(0), s(_s), z(0), r(_r) {
		z = s/8 + (s%8 > 0);
		if(z) p = new uchar[z];
    }
    /**
      * Konstruktor kopiujący.
      * @param x Kopiowany wektor bitowy.
      */
    bitvector(const bitvector& x) : p(0), s(x.s), z(x.z), r(x.z) {
		p = new uchar[z];
		for(uint i=0;i<z;++i) p[i]=x.p[i];
    }
    /**
      * Destruktor.
      */
    ~bitvector() { delete [] p; }
    class ref;
    friend class ref;
	/**
	  * Klasa referencyjna.
	  * Pozwala na ,,przyjemne'' operacje na bitsecie.
	  */
    class ref {
		/**
		  * Wskaźnik na bajt.
		  */
		uchar *p;
		/**
		  * Maska bitowa.
		  */
		uint i;
    public:
		/**
		  * Konstruktor.
		  * @param _p Wskaźnik na bajt zawierający dane.
		  * @param _i Maska bitowa.
		  */
		explicit ref(uchar *_p, uint _i) : p(_p), i(_i) {}
		/**
		  * Operator przypisania.
		  * Zwraca bool by można było łańcuchować wyrażenia, np bs[0]=bs[1]=bs[2]=1;
		  */
		bool operator=(bool val) {
			if(((*p)&i) ^ val) (*p)^=i;
			return ((*p)&i)>0;
		}
		/**
		  * Operator konwersji do bool.
		  */
		operator bool() {
			return ((*p)&i)>0;
		}
    };
	/**
	  * Operator odwołania do tablicy.
	  * Upewnia się, że element ,,x'' należy do tablicy, jeśli nie to alokuje nową tablicę o rozmiarze
	  * \f$ r\left\lceil\frac{A\left\lceil\frac{x+1}{A}\right\rceil}{r}\right\rceil \f$
	  * bajtów.
	  */
	ref operator[](uint x) {
		if(x>=s) {
			uint nz = (x+1)/8+((x+1)%8>0);
			if(nz%r) nz += r-nz%r;
			uchar *np = new uchar[nz];
			for(uint i=0;i<z;++i) np[i]=p[i];
			delete [] p;
			p = np;
			s = x+1;
			z = nz;
		}
		return ref(p+x/8,1<<x%8);
	}
};

}

#endif
