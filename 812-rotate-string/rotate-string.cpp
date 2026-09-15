class Solution {
public:

//*** Brute solution
    bool rotateString(string s, string goal) {
    //     if(s.length() != goal.length())
    //     return false;

    //     for(int i = 0; i < s.length(); i++)
    //     {
    //         string rotated = s.substr(i) + s.substr(0,i);
    //         if(rotated == goal)
    //         {
    //             return true;
    //         }
    //     }
    //     return false;
    //       O(N2)

     if(s.length() != goal.length())
     {
        return false;
     }

        string doubledS = s + s;
       return doubledS.find(goal) != string::npos;
        //   O(N)
    }
};