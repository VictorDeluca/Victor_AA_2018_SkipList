//2-layer skip list (Sqrt-decomposition memes)
#include <bits/stdc++.h>
using namespace std;

typedef struct nodd{
	int val;
	nodd* next;
	nodd* below;
}nodd;

int sqr; nodd* root; nodd* rootl2;

nodd* init(int val){
	nodd* n = (nodd*)malloc(sizeof(nodd));
	n->val = val;
	n->next = root;
	n->below = NULL;
	return n;
}

nodd* initl2(int val){
	nodd* n = (nodd*)malloc(sizeof(nodd));
	n->val = val;
	n->next = rootl2;
	n->below = NULL;
	return n;
}

int main(){
	vector<int> valores; int v1,i,j,k;
	root = NULL; rootl2 = NULL;
	int n; scanf("%d",&n);
	while(n--){ 
		scanf("%d",&v1);
		valores.push_back(v1);
	}
	sort(valores.begin(),valores.end());

	sqr = sqrt(valores.size());
	//Build first layer
	for(i=0;i<valores.size();i++){
		nodd* t = init(valores[i]);
		root = t;
	}
	//Build second layer O(n + sqrt(n)) with two-pointers approach
	nodd* cur = root;
	for(i=0;i<valores.size();i++){
		cur = cur->next;
		if(i%sqr==0){
			nodd *t = initl2(valores[i]);
			rootl2 = t;
			t->below = cur;
		}
	}

	int q; //Queries
	scanf("%d",&q);
	for(i=0;i<q;i++){
		int val; scanf("%d",&val);
		cur = rootl2; int found = 0;
		while(cur!=NULL){
			if(cur->val == val || cur->next->val == val){ found = 1; break; }
			if(cur->next == NULL || cur->next->val < val) cur = cur->below;
			else cur = cur->next;
		}

		if(found) printf("O elemento esta na lista\n");
		else printf("O elemento nao esta na lista\n");
	}

	return 0;
}