//implement class to club all the marks of a particular student
class marks {
    public:
    int p, c, m;
    marks(int p,int c,int m) {
        this -> p = p;
        this -> c = c;
        this -> m = m;
    }
};
 
//self implemented comparator function we will pass to the
//stl function sort
bool comparator(marks s1, marks s2) {
   
    //if marks of physics are not equal sort according to the lesser marks
    if(s1.p != s2.p)
        return s1.p < s2.p;
       
    //if marks of phy are equal sort according to the greater chem marks    
    else if(s1.c != s2.c)
        return s1.c > s2.c;
   
    //if marks of chem and phy both equal sort according to lesser math marks
    else
        return s1.m < s2.m;
       
}
 
class Solution{
    public:
   
    void customSort (int phy[], int chem[], int math[], int N)
    {
        //array of objects for all students
        vector<marks> M;
        // your code here
        for(int i = 0; i < N; i++) {
           
            //calling constructor to create an object for a particular student
            //and pushing it to the vector
            marks m (phy[i], chem[i], math[i]);
            M.push_back(m);
        }
       
        //use STL sort with our self defined comparator
        sort(M.begin(), M.end(), comparator);
       
        //assign the newly sorted values back to the arrays
        for(int i = 0; i < N; i++) {
            phy[i] = M[i].p;
            chem[i] = M[i].c;
            math[i] = M[i].m;
        }
    }
};
