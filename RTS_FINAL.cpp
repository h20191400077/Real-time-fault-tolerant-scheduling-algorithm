#include <bits/stdc++.h>


using namespace std;
#define ll long long
#define MOD 10


 vector<ll> v_task;
	ll n, a, pos, pos1, pos2;
	vector<ll> temp;


ll getLength(ll n) 
{ 
    return floor(log10(n) + 1); 
}


void sorted() {
	
ll k1;

		cout << "\n\n\nFAULT TOLERANT ALGORITHM WITH SORTING OF TASKS BY LENGTH-\n\n\n";

	 vector<vector<ll> > vec_primary( 15 , vector<ll> (8, 0));  

    vector<vector<ll> > vec_backup( 15 , vector<ll> (8, 0));  
	
	
     struct timespec start, end; 

    clock_gettime(CLOCK_MONOTONIC, &start); 

  
	   std::vector<ll> s_task;

	 cout << "\nENTERED TASKS SET ARE -\n";
     for(ll i = 0; i < n; i++) {
     	
        cout << v_task[i] << endl;
   
    }

	ll temp1 = v_task[a-1];
    s_task = v_task;

    sort(s_task.begin(), s_task.end());


    cout << endl;
	cout << "\nSORTED SEQUENCE OF TASKS -\n";
    for(ll i = 0; i < n; i++) {
    	
        cout << s_task[i] << endl;
    if(s_task[i]==temp1)
    k1=i;
    
	}

    cout << endl;

    vector<ll> length;

    ll w = 0;
    for(ll i = 0; i < n; i++) {
    	
        ll k = getLength(s_task[i]);
        length.push_back(k);
        ll l = k - 1;
        
        for(ll j = 0; j < 8; j++) {
        	
            while(s_task[i] != 0) {
            	
                ll d = s_task[i] % 10;
                vec_primary[w][l] = d;
                s_task[i] = s_task[i] / 10;
                l--;
            }  
            if(j >= k) {
                vec_primary[w][j] = 0;
            }

        }
        w++;
    }


        cout << "\nLengths of each sorted task : ";
        for(ll i = 0; i < n; i++) {
            cout << length[i] << " units ";
        }
        cout << endl;
        
	cout << "\nTASKS SCHEDULED ON 15 VIRTUAL MACHINES -\n";
   
    for(ll i = 0; i < 15; i++) {
    	
        for(ll j = 0; j < 8; j++) {
        	
            cout << vec_primary[i][j] << "   ";
        }
        cout << "\n";
    } 

    cout << endl;
		vec_backup = vec_primary;
	

    ll k = 8 - pos;
    for(ll i = 0; i < n; i++) {
    
    	
        if((length[i] <= k )&&(i!=k1))  {
        	
            for(ll j = pos, m = 0; j < 8, m < 8; j++, m++) {
            	
                vec_backup[a-1][j] = vec_primary[i][m];
            }
            pos = pos + length[i];
            k = k - length[i];
        }       
    }
		
		cout << "\nTHE SCHEDULED BACKUP VIRTUAL MACHINE ON WHICH FAULT OCCURED -\n";
		
		ll n = v_task[a-1];
		for(; n; n/=10)
  			temp.push_back( n%10 );
  			
  			reverse(temp.begin(), temp.end());
		
		
		
		for(ll i = 0; i < pos2; i++) {
			cout << temp[i] << " ";
		}
        for(ll j = pos2; j < 8; j++) {
            cout << vec_backup[a-1][j] << " ";
        }
        cout << endl;
        
        
    clock_gettime(CLOCK_MONOTONIC, &end); 

    double time_taken; 
    time_taken = (end.tv_sec - start.tv_sec) * 1e9; 
    time_taken = (time_taken + (end.tv_nsec - start.tv_nsec)) * 1e-9; 
  
    cout << "\nTime taken by sorted function is : " << fixed 
         << time_taken << setprecision(9); 
    cout << " sec\n\n" << endl;
}












void unsorted() {


	vector<vector<ll> > vec_primary( 15 , vector<ll> (8, 0));  

    vector<vector<ll> > vec_backup( 15 , vector<ll> (8, 0));  

    struct timespec start, end; 

    clock_gettime(CLOCK_MONOTONIC, &start); 

   
	
	cout << "\n\n\nNORMAL REARRANGEMENT ALGORITHM-\n\n\n";
	
   std::vector<ll> s_task;
	

	 cout << "\nENTERED TASKS SET ARE -\n";
     for(ll i = 0; i < n; i++) {
        cout << v_task[i] << endl;
    }


    s_task = v_task;
    //sort(s_task.begin(), s_task.end());


    cout << "\n";

    cout << "\n";

    vector<ll> length;

    ll w = 0;
    for(ll i = 0; i < n; i++) {
        ll k = getLength(s_task[i]);
        length.push_back(k);
        ll l = k - 1;
        for(ll j = 0; j < 8; j++) {
            while(s_task[i] != 0) {
                ll d = s_task[i] % 10;
                vec_primary[w][l] = d;
                s_task[i] = s_task[i] / 10;
                l--;
            }  
            if(j >= k) {
                vec_primary[w][j] = 0;
            }

        }
        w++;
    }
        cout << "\nLengths of each tasks : ";
        for(ll i = 0; i < n; i++) {
            cout << length[i] << " units ";
        }
        cout << "\n";
        
       	vec_backup = vec_primary;
	
		cout << "\nTASKS SCHEDULED ON 15 VIRTUAL MACHINES -\n";

    for(ll i = 0; i < 15; i++) {
        for(ll j = 0; j < 8; j++) {
            cout << vec_primary[i][j] << "   ";
        }
        cout << "\n";
    } 

    cout << "\n";


    ll k = 8 - pos1;
    for(ll i = 0; i < n; i++) {
        if(length[i] <= k && i != a-1) {
            for(ll j = pos1, m = 0; j < 8, m < 8; j++, m++) {
                vec_backup[a-1][j] = vec_primary[i][m];
            }        
             pos1 = pos1 + length[i];
            k = k - length[i];
        }    
    }

	
		cout << "\nTHE SCHEDULED BACKUP VIRTUAL MACHINE ON WHICH FAULT OCCURED -\n";
		
		for(; v_task[a-1]; v_task[a-1]/=10)
  			temp.push_back( v_task[a-1]%10 );
  			
  			reverse(temp.begin(), temp.end());
		
		for(ll i = 0; i < pos2; i++) {
			cout << temp[i] << " ";
		}
        for(ll j = pos2; j < 8; j++) {
        	
            cout << vec_backup[a-1][j] << " ";
        }
        cout << "\n";
        
        
 l:   clock_gettime(CLOCK_MONOTONIC, &end); 

    double time_taken; 
    time_taken = (end.tv_sec - start.tv_sec) * 1e9; 
    time_taken = (time_taken + (end.tv_nsec - start.tv_nsec)) * 1e-9; 
  
    cout << "\nTime taken by unsorted function is : " << fixed 
         << time_taken << setprecision(9); 
    cout << " sec" << "\n" << "\n"; 
}

int main()
{
	cout << "Enter no. of tasks - ";
    cin >> n;
    
     for(ll i = 1; i <= n; i++) {
     	cout << "Enter task " << i << " of max length 8 - ";
        cin >> a;
        v_task.push_back(a);
    }
    
    
    cout << "Enter the task number and position after which fault should occur -\n";
    cout << "Task number - ";
    cin >> a;
    cout << "Position - ";
    cin >> pos;
    pos1 = pos;
	pos2 = pos;
    sorted();
    unsorted();
	system("pause");


    



return 0;
}
