    stack<int>s;
    int i=0;
    while(i!=n){
        s.push(i);
        i++;
    }
    while(s.size()>=2){
        int x=s.top();
        s.pop();
        int y=s.top();s.pop();
        if(knows(x,y))
            s.push(y);
        else
            s.push(x);
    }
    int celeb=s.top();
    for(int i=0;i<n;i++){
        if(!knows(i,celeb) and knows(celeb,i));
           return -1;
    }
    cout<<celeb<<endl;
    return celeb;
    }
   
