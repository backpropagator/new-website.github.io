#include <bits/stdc++.h>

using namespace std;

// Complete the timeInWords function below.
string timeInWords(int h, int m) {
    vector<string> numbers = {
        "zero", 
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine",
        "ten",
        "eleven",
        "twelve",
        "thirteen",
        "fourteen",
        "fifteen",
        "sixteen",
        "seventeen",
        "eighteen",
        "nineteen",
        "twenty",
        "twenty one",
        "twenty two",
        "twenty three",
        "twenty four",
        "twenty five",
        "twenty six",
        "twenty seven",
        "twenty eight",
        "twenty nine"
    };
    
    string hour, minutes;
    
    if(m == 00){
        return (numbers[h] + " o' clock");
    }
    else if(m == 15){
        return ("quarter past " + numbers[h]);
    }
    else if(m == 45){
        return ("quarter to " + numbers[h+1]);
    }
    else if(m == 30){
        return ("half past " + numbers[h]);
    }
    else if(m < 30 && m > 0){
        if(m < 10){
            return (numbers[m] + " minute past " + numbers[h]);
        }
        return (numbers[m] + " minutes past " + numbers[h]);
    }
    else if(m > 30 && m < 60){
        return (numbers[60-m] + " minutes to " + numbers[h+1]);
    }else{
        return "Nothing";
    }
        


}

int main()
{
    int h, m;
    cin>>h>>m;
    cout<<timeInWords(h,m)<<"\n";

    return 0;
}