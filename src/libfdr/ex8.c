#include <stdio.h>
#include "ex8.h"
int Connected(JRB g,int a,int b){// kiểm tra xem có cạnh từ a đến b không
	JRB tree=NULL,ptr=NULL;
	ptr=jrb_find_int(g,a);
	if(ptr){		
		tree=(JRB)jval_v(ptr->val);
		jrb_traverse(ptr,tree){			
			if(b==jval_i(ptr->key)) return 1;
		}
		return 0;
	}
	else return 0;
}
JRB GetAdjacentList(JRB g,int a){// trả về danh sách các đỉnh mà từ a có thể đến được
	JRB ptr=jrb_find_int(g,a);
	if(ptr) return (JRB)jval_v(ptr->val);
	else return NULL;	
}
int InDegree(JRB g,int a){// tính bậc vào của một đỉnh
	int count=0;
	JRB ptr=NULL,subptr=NULL,subtree=NULL;


	jrb_traverse(ptr,g){
		subtree=(JRB)jval_v(ptr->val);
		jrb_traverse(subptr,subtree){
			if(jval_i(subptr->key) == a) {count++;break;}
		}
	}
	return count;
}
int OutDegree(JRB g,int a){// tính bậc ra của một đỉnh
	int count=0;
	JRB ptr=NULL,subptr=NULL,subtree=NULL;
	

	jrb_traverse(ptr,g){
		if(jval_i(ptr->key) == a){
			subtree=(JRB)jval_v(ptr->val);
			jrb_traverse(subptr,subtree){
				count++;
			}
		}		
	}
	return count;
}