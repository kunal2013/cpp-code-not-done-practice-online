
# include <iostream>
# include <string>       // for empty()
# include <sstream>
# include <algorithm>    // for count - '/'
using namespace std ;

bool isleap (int year)
{
    return (((year%4==0) && (year%100!=0)) || (year%400==0)) ;
}

bool isValidDate(int d, int m, int y)
{
    if (d<1 || d>31 || m<1 || m>12)
        return false ;

    if (m==2)             // if month is feb no need to check rest months, so return
    {
        if (isleap(y))
            return (d<=29) ;
        else
            return (d<=28) ;
    }

    if (m==4 or m==6 or m==9 or m==11)
        return (d<=30) ;           // 30 is of concern 31 case will be covered from earlier cases

    return true ;         // for rest cases
}

/////////////////////////////////////////////////////////////////////////
int main()
{
    string S, T ;
    int a[3], flag ;
    cout << "\n** Enter your date ** \nFormat - (DD/MM/YY) enter -- " ;
    getline(cin, S) ;           // use getline() function to read a line of string and store into S variable.
    int i = 0;
    if (count(S.begin(),S.end(),'/')==2)
    {
        if (S[S.size()-1]=='/')           // for checking last char, as with getline it cannot be checked
        {
            cout << "** yr Year input is WRONG **\n" ;
            exit(0) ;
        }
        stringstream X(S) ; // X is an object of stringstream that references the S string
        while (getline(X, T, '/'))   // use while loop to check the getline() function condition
        {
            if (T.empty())
            {
                cout<<"** yr input in date/month is wrong **\n" ;
                exit(0) ;
            }
            a[i++] = stoi(T) ;
        }
    }
    else
    {
        cout << "\nInvalid input. '\\' was missing. \n" ;
        exit(0) ;
    }

    if (isValidDate(a[0],a[1],a[2]))
        cout << "\nvalid date\n" ;
    else
        cout << "\nInvalide date\n" ;

    return 0;
}

/*   getline(X, T, '/'))
    X represents to read the string from stringstream, T use for store the token string
    and, ' ' whitespace represents to split the string where whitespace is found. */


