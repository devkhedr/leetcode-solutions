class Solution {
public:
   bool isPalindrome(int x) {
    if(x<0)return 0;
    int numofdigits  = 0, t = x;
    while(t!=0)
    {
        numofdigits++;
        t/=10;
    }
    bool flag = (numofdigits%2);
    numofdigits/=2;
    int temp = 0;
    while(numofdigits--)
    {
        temp *=10;
        temp+=(x%10);
        x/=10;
    }
    if(flag)x/=10;
    if(x<0&&temp>0)return 0;
    return (abs(temp) == abs(x));
}
};