int main(){
	char bracket[100], b;
	int max=0, temp, u=0;
	stack* cstack = create_stack(100,sizeof(char));
	scanf("%s", bracket);
	if(bracket[0]==')'||bracket[0]=='>'||bracket[0]==']'||bracket[0]=='}'){
		printf("invalid");
	}
	else{
		push(cstack,&bracket[0]);
		for(int i=1;i<strlen(bracket);i++){
      	temp = get_size(cstack);
			if(max<temp) max = temp;
			if(bracket[i]=='('||bracket[i]=='<'||bracket[i]=='['||bracket[i]=='{'){
				push(cstack,&bracket[i]);
			}
			else{
				get_element(cstack,get_size(cstack)-1,&b);
				if(bracket[i] == ')'){
          if(b == '(') pop(cstack,&b);
        }
        else if(bracket[i] == ']'){
          if(b == '[') pop(cstack,&b);
        }
        else if(bracket[i] == '>'){
          if(b == '<') pop(cstack,&b);
        }
        else if(bracket[i] == '}'){
          if(b == '{') pop(cstack,&b);
        }
        temp = get_size(cstack);
        if(max<temp) max = temp;
			}
		
		}
		get_element(cstack,get_size(cstack)-1,&b);
		if(b=='('||b=='<'||b=='['||b=='{') printf("invalid");
		else printf("%d",max);
	}	
    return 0;
}
