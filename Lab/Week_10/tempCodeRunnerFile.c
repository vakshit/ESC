NODE* head=NULL,*tail=NULL,*pt;
    int num;
    for (int i=0; i<n; i++){
        scanf("%d",&num);
        pt=createNode(num);
        if(head==NULL)
            head=tail=pt;
        else{
            tail->next=pt;
            tail=pt;
        }
    }
    return head;