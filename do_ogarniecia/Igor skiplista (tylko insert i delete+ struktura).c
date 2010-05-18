const int max_h=16;
struct skipek{
     	struct skipek** nexts;  
   	double data; }; 
   
struct skiphead{
	int height;
	struct skipek* head;
	};
void insert(struct skiphead* prehead, double data)
{
	struct skipek* p=prehead->head;
	int h=losuj(prehead->height+1);
	if (h>prehead->height)prehead->height=h;
	struct skipek* wstawiany=(struct skipek*)malloc(sizeof(struct skipek));
	wstawiany->data=data;
	wstawiany->nexts=(struct skipek**)malloc(h*sizeof(struct skipek*));
	int i=0;
	for(i=h-1;i>=0;i--)
		{
			while(p->nexts[i] && p->nexts[i]->data<data)p=p->nexts[i];
			wstawiany->nexts[i]=p->nexts[i];
			p->nexts[i]=wstawiany;
		}
}

void delete(struct skiphead* prehead, double data)
{
	struct skipek * temp=NULL;
	struct skipek * p=prehead->head;
	for(i=prehead->height-1;i>=0;i--)
		{
			while(p->nexts[i] && p->nexts[i]->data<data)p=p->nexts[i];
			if(p->nexts[i] && p->nexts[i]->data==data)
				{
					if (i==0) temp=p->nexts[i];
					p->nexts[i]=p->nexts[i]->nexts[i];
				}
		}
		if (temp) free(temp);
		if(!prehead->nexts[prehead->height-1]) prehead->height--;
}
	
	