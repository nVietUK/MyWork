#include<bits/stdc++.h>

using namespace std;

class Box {
    private:
        int l, b, h;
    public:
        Box() {
            l = b = h = 0;
        };
        Box(int l, int b, int h) {
            this->l = l;
            this->b = b;
            this->h = h;
        }
        Box(const Box& in) {
            l = in.l;
            b = in.b;
            h = in.h;
        }
        int getLength() { return l; };
        int getBreadth() { return b; };
        int getheight() { return h; };
        long long CalculateVolume() { return (long long)l * b * h; };
        friend ostream& operator <<(ostream& out, Box& B) {
            out << B.l << " " << B.b << " " << B.h;
            return out;
        }
        friend bool operator < (Box& b1, Box& b2)
        {
            if((b1.l < b2.l) || (b1.l == b2.l && b1.b < b2.b) ||
               (b1.l == b2.l && b1.b == b2.b && b1.h <b2.h))
                return(true);
            else
                return(false);
        }
};

void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
    freopen("test.inp", "r", stdin);
	check2();
}