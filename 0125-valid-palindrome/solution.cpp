class Solution {
public:

    int isalnum(char a){
        if((a>='A' && a<= 'Z') ||(a>='a' && a<= 'z') ||(a<='9' && a>='0')) return 1 ;
        return 0 ;
    }

    char tolow(char a){
        if((a>='A' && a<= 'Z')) a+=32;
        return a ;
    }

    bool isPalindrome(string s) {
        int st = 0 , end = s.length()-1 ;
        while(st<end){
            while(!isalnum(s[st]) && st<end){
                st++;
            }
            while(!isalnum(s[end]) && st<end){
                end--;
            }
            if(tolow(s[st])!= tolow(s[end])) return false ;
            st++;end--;
        }
        return true ;
    }
};
