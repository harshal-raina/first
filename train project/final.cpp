#include "validation.h"
#define pii pair<long long int,int>
#define MAX 100000000000000000
pii p ;
multiset<pii> myset ;
long long int dist[100004] ;
bool visited[100004] ;
int path[100004] ;
vector< pii> graph[100004] ;
void dijikstra(int a, int b , int v ) {
        memset( visited , false , sizeof(visited) ) ;
		for( int i = 0 ; i <= v ; i++ ) dist[i] = MAX ;
		dist[a] = 0 ;//distance of source from source is 0...
		visited[a] = true ;
		//making pair...
		p.first = dist[a] ;
		p.second = a ;
		myset.insert(p) ;//inserting first pair in set ;
		//cout << "entering algo : " << endl ;
		while( !myset.empty() ) {
			p = *( myset.begin() ) ;
            visited[p.second] = true ;
            for( vector< pii>::iterator it = graph[p.second].begin() ; it != graph[p.second].end() ; it++ ) {
                if( !visited[(*it).second] && ( dist[p.second] + (*it).first ) < dist[(*it).second] ) {
                    myset.erase(make_pair(dist[(*it).second],(*it).second ) );
                    dist[(*it).second] =  dist[p.second] + (*it).first  ;
                    myset.insert(make_pair(dist[(*it).second],(*it).second ) ) ;
                    path[(*it).second] = p.second ;
                }
            }
            myset.erase(p) ;
		}
}

void irctc(char Infilename[],char Outfilename[])
{
    cout.sync_with_stdio(0) ;
	int t , v , k ;
	long long int a, b , c ;
	 #ifndef ONLINE_JUDGE
        freopen( Infilename , "r" , stdin ) ;
        freopen( Outfilename , "w" , stdout ) ;
    #endif // ONLINE_JUDGE
    cin >> t ;
	 while( t-- ) {
		cin >> v >> k ;
        long long int total = 0 ;
		for( int i = 0 ; i <= v ; i++ ) graph[i].clear() ;//graph cleared...
		for( int i = 0 ; i < k ; i++  ) {
			cin >> a >> b >> c ;
			p.first = c ; p.second = b ;
			graph[a].push_back(p) ;
			p.second = a ;
			graph[b].push_back(p) ;
		}
        cin >> a >> b >> c ;//path from a to c via b needs to be calculated....
		dijikstra(b,c,v) ;
		total += dist[c] ;
        //cout << "executed algo : " << endl ;
        stack<int> my_stack ;
        if( dist[c] == MAX ) { cout << "No Train Found." << endl ;  }
        else {
            int j = path[c] ;
            my_stack.push( c ) ;
            while( 1 ) {
                my_stack.push( j ) ;
                if( j == b ) break ;
                j = path[j] ;
            }
            /*while( !my_stack.empty() ) {
            cout << my_stack.top() << ' ' ;
            my_stack.pop() ;
            }
            */
            my_stack.pop() ; //b is popped otherwise it will appear double in stack ...
            dijikstra(a,b,v) ;
            total += dist[b] ;
        //cout << "executed algo : " << endl ;
        if( dist[b] == MAX ) { cout << "No Train Found." << endl ;  }
        else {
                cout << total << endl ;
            int j = path[b] ;
            my_stack.push( b ) ;
            while( 1 ) {
                my_stack.push( j ) ;
                if( j == a ) break ;
                j = path[j] ;
            }
            while( !my_stack.empty() ) {
            cout << my_stack.top() << ' ' ;
            my_stack.pop() ;
            }
            cout << endl ;
        }
        }
	}

}

int main(int argc,char* argv[]) {
    ifstream infile(argv[1]);
    unsigned int valid_or_not;
    if(!infile)
    {
        cout<<"No such file exist in the present directory!\n";
    }

    else
    {
        valid_or_not=validation(argv[1]);

        if(valid_or_not==0)
        {
            cout<<"Successfully Executed!\n";
            irctc(argv[1],argv[2]);
        }
        else if(valid_or_not==1)
        {
            cout<<"Unexpected Input on the first line(May contain more than one unsigned integer)\n";
        }
        else if(valid_or_not==2)
        {
            cout<<"Wrong number of input given in any line(More than 3 integer in a line\n";
        }
        else if(valid_or_not == 3)
        {
            cout<<"More number of lines having two integer values(Invalid!)\n";
        }
        else if(valid_or_not == 4)
        {
            cout<<"Number of lines in Input file is more than expected(Invalid!)\n";
        }
        else if(valid_or_not == 5)
        {
            cout<<"Number of lines in Input file is less than expected(Invalid!)\n";
        }
    }
	return 0 ;
}
