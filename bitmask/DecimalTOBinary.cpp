string DTB(int num)
{
    string str;
      while(num){
      if(num & 1) 
        str+='1';
      else // 0
        str+='0';
      num>>=1;  
    }   
    reverse(begin(str),end(str));
    return str;
}