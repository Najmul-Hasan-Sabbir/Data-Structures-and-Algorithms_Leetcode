class Solution {
public:
    string reverseWords(string s) {
       
   stringstream ss(s);
   //  Using stringstream to handle the spaces automatically
   string word;
   vector<string>words;
// Extracting words and storing them in a vector
   while(ss>>word){

   words.push_back(word);
     
   }
   string result="";
   for(int i=words.size()-1; i>=0; i--){

   result+=words[i];


// Adding a space between words, but not after the last one
if(i>0){
    result+=" ";
}
   }

return result;

    }
};