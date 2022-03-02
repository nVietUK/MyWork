#include <bits/stdc++.h>

using namespace std;

const unsigned maxN = 200005;

int 
    n, k, root, maxDepth,
    par[maxN][20],
    depth[maxN];
vector<int> 
    a[maxN],
    meeting[maxN/2];

void elementDepth(int x) {
    if (depth[x]>maxDepth) 
        maxDepth=depth[x];
    for (int i=0;i<int(a[x].size());i++) {
        depth[a[x][i]]=depth[x]+1; 
        elementDepth(a[x][i]);
    }
}

void init() {
    for (int j=1;1<<j<=maxDepth;j++)
        for (int i=1;i<=n;i++)
            par[i][j]=par[par[i][j-1]][j-1];
}

int LCA(int x,int y) {
    int log;
    if (depth[x]<depth[y]) 
        swap(x,y);
    for (log = 0; 1<<log <= depth[x]; log++);
    for (int i = log; i >= 0; i--)
        if (depth[x]-(1<<i)>=depth[y]) 
            x=par[x][i];
    if (x == y) 
        return x;
    for (int i = log; i >= 0; i--)
        if (par[x][i] && par[x][i]!=par[y][i]) 
            x=par[x][i], y=par[y][i];
    return par[x][0];           
}

int calcMeeting(vector <int> meeting) {
    int x=meeting[0], y, furthestDist=0, ans=0;
    for (int i=1;i<int(meeting.size());i++) {
        int j=meeting[i], dist=depth[x]+depth[j]-2*depth[LCA(x,j)];
        if (dist>furthestDist) furthestDist=dist, y=j;
    }
    for (int i=0;i<int(meeting.size());i++) {
        int j=meeting[i], dist=depth[y]+depth[j]-2*depth[LCA(y,j)];
        if (dist>ans) ans=dist;
    }
    return ans;
}

int main() {
    int x; cin >> n >> k;
    for (int i=1;i<=n;i++)  {
        cin >> x >> par[i][0];
        a[par[i][0]].push_back(i);
        meeting[x].push_back(i);
        if (!par[i][0]) 
            root = i;
    }
    elementDepth(root); init();
    for (int i=1;i<=k;i++) 
        cout << calcMeeting(meeting[i]) << "\n";
}