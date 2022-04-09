#include<bits/stdc++.h>
using namespace std;

int sz[30010],d[30010],fa[30010];
int find(int x) {
  if(fa[x]!=x)
  {
    int root=find(fa[x]);
    d[x]+=d[fa[x]];
    fa[x]=root;
  }
  return fa[x];
}

int main() {
  int t;
  for(int i=0;i<30010;i++) d[i]=0,sz[i]=1,fa[i]=i;

  cin>>t;
  while(t--){
    char op[2];
    int a,b;
    scanf("%s%d%d",op,&a,&b);
    int pa=find(a),pb=find(b);
    if(op[0]=='M'){
      if(pa!=pb)
      {
          fa[pa]=pb;
          d[pa]=sz[pb];
          sz[pb]+=sz[pa];
      }
    }
    else{
      if(pa!=pb) cout<<-1<<endl;
      else printf("%d\n",max(0,abs(d[a]-d[b])-1));
    }
  }
  return 0;
}
