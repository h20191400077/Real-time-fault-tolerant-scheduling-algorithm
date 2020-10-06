#include <bits/stdc++.h>


using namespace std;
#define ll long long
#define MOD 10


ll getLength(ll n) 
{ 
    return floor(log10(n) + 1); 
}


void unsorted() {

    struct timespec start, end; 
    ll n, a, pos;

    clock_gettime(CLOCK_MONOTONIC, &start); 

    vector<ll> v_task;

    vector<vector<ll> > vec_primary( 15 , vector<ll> (6, 0));  

    vector<vector<ll> > vec_backup( 15 , vector<ll> (6, 0));  
    
//	cout << "Enter no. of tasks - ";
    cin >> n;
	
    for(ll i = 0; i < n; i++) {
        cin >> a;
        v_task.push_back(a);
    }


     for(ll i = 0; i < n; i++) {
        cout << v_task[i] << endl;
    }

    std::vector<ll> s_task;

    s_task = v_task;
    //sort(s_task.begin(), s_task.end());


    cout << endl;

    for(ll i = 0; i < n; i++) {
        cout << s_task[i] << endl;
    }

    cout << endl;

    vector<ll> length;

    ll w = 0;
    for(ll i = 0; i < n; i++) {
        ll k = getLength(s_task[i]);
        length.push_back(k);
        ll l = k - 1;
        for(ll j = 0; j < 6; j++) {
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
        cout << "Lengths of each tasks : ";
        for(ll i = 0; i < n; i++) {
            cout << length[i] << " ";
        }
        cout << endl;

    for(ll i = 0; i < 15; i++) {
        for(ll j = 0; j < 6; j++) {
            cout << vec_primary[i][j] << " ";
        }
        cout << endl;
    } 

    cout << endl;

    vec_backup = vec_primary;

    cin >> a >> pos;


    ll k = 6 - pos;
    for(ll i = 0; i < n; i++) {
        if(length[i] <= k) {
            for(ll j = pos, k = 0; j < 6, k < 6; j++, k++) {
                vec_backup[a-1][j] = vec_primary[i][k];
            }
            break;
        }
    }

//for(ll i = 0; i < 15; i++) {
        for(ll j = 0; j < 6; j++) {
            cout << vec_backup[a-1][j] << " ";
        }
        cout << endl;
    clock_gettime(CLOCK_MONOTONIC, &end); 

    double time_taken; 
    time_taken = (end.tv_sec - start.tv_sec) * 1e9; 
    time_taken = (time_taken + (end.tv_nsec - start.tv_nsec)) * 1e-9; 
  
    cout << "Time taken by unsorted function is : " << fixed 
         << time_taken << setprecision(9); 
    cout << " sec" << endl << endl; 
}

void sorted() {

     struct timespec start, end; 
    ll n, a, pos;

    clock_gettime(CLOCK_MONOTONIC, &start); 

    vector<ll> v_task;

    vector<vector<ll> > vec_primary( 15 , vector<ll> (6, 0));  

    vector<vector<ll> > vec_backup( 15 , vector<ll> (6, 0));  

    cin >> n;

    for(ll i = 0; i < n; i++) {
        cin >> a;
        v_task.push_back(a);
    }


     for(ll i = 0; i < n; i++) {
        cout << v_task[i] << endl;
    }

    std::vector<ll> s_task;

    s_task = v_task;
    sort(s_task.begin(), s_task.end());


    cout << endl;

    for(ll i = 0; i < n; i++) {
        cout << s_task[i] << endl;
    }

    cout << endl;

    vector<ll> length;

    ll w = 0;
    for(ll i = 0; i < n; i++) {
        ll k = getLength(s_task[i]);
        length.push_back(k);
        ll l = k - 1;
        for(ll j = 0; j < 6; j++) {
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


        cout << "Lengths of each sorted task : ";
        for(ll i = 0; i < n; i++) {
            cout << length[i] << " ";
        }
        cout << endl;

    for(ll i = 0; i < 15; i++) {
        for(ll j = 0; j < 6; j++) {
            cout << vec_primary[i][j] << " ";
        }
        cout << endl;
    } 

    cout << endl;

    vec_backup = vec_primary;

    cin >> a >> pos;


    ll k = 6 - pos;
    for(ll i = 0; i < n; i++) {
        if(length[i] <= k) {
            for(ll j = pos, k = 0; j < 6, k < 6; j++, k++) {
                vec_backup[a-1][j] = vec_primary[i][k];
            }
            break;
        }
    }

//for(ll i = 0; i < 15; i++) {
        for(ll j = 0; j < 6; j++) {
            cout << vec_backup[a-1][j] << " ";
        }
        cout << endl;
    clock_gettime(CLOCK_MONOTONIC, &end); 

    double time_taken; 
    time_taken = (end.tv_sec - start.tv_sec) * 1e9; 
    time_taken = (time_taken + (end.tv_nsec - start.tv_nsec)) * 1e-9; 
  
    cout << "Time taken by sorted function is : " << fixed 
         << time_taken << setprecision(9); 
    cout << " sec" << endl;
}

int main()
{
	

   unsorted();
   sorted();
   /* ll k = 6 - pos;
    ll z = 0;
    while(k != 0) {
        if(z != a) {
            if(length[z] <= k) {
                for(ll i = 0; i < length[z]; i++)
                    cout << vec_primary[z][i];
            }
        }
            else  {
             z++;

             continue;
              }
    
    
    pos = pos + length[z];
    k = 6 - pos;
    z++;
    }*/


    



return 0;
}
