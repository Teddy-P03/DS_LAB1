int main(){
	int n, c, i, j;
	scanf("%d %d",&n,&c);
	int narr[n];
	int marr[n];
	stack* cstack = create_stack(c,sizeof(int));
	for(i=0;i<n;i++){
		scanf("%d",&marr[i]);
		narr[i] = i+1;
	}
	i = 0;
	j = 0;
	while(1){
		if(narr[i] == marr[j]){
			while(!is_empty(cstack)){
				pop(cstack,&narr[i]);
				i-=1;
			}
			i+=1;
			j+=1;
		}
		else{
			if(is_full(cstack) != 0) break;
			push(cstack,&narr[i]);
			i+=1;
		}
		if(marr[j]>n) break;
		if(j==n) break;
	}
	if(marr[j]>n) printf("false");
	else if(j==n){
		printf("true");
	}
	else printf("false");
    return 0;
}
