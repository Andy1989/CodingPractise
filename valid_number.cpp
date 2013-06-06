/*
 * Validate if a given string is numeric.
 *
 * Some examples:
 * "0" => true
 * " 0.1 " => true
 * "abc" => false
 * "1 a" => false
 * "2e10" => true
 *
 * Note: It is intended for the problem statement to be ambiguous. 
 * You should gather all requirements up front before implementing one.
 */
 
class Solution {
public:
  bool isNumber(const char *s) {
  // Start typing your C/C++ solution below
  // DO NOT write int main() function
  unsigned int length = strlen(s);
  int dot = 0;
  int e = 0;
  int num = 0;
  char *head = (char*)s;
  char *end = head + length -1;
  char *temp = NULL;
  if(head == NULL)
    return false;
        
  while(*head == ' ') {
    head++;
  }
  while(*end == ' ') {
    end--;
  }
        
  for(temp = head; temp != end; temp++) {
    if(*temp - '0' < 0 || *temp - '0' > 9) {
      if(*temp == '-' || *temp == '+') {
    if(temp != head){
    if(*(temp-1) != 'e')
	    return false;
	}
	if(*(temp+1) - '0' < 0 || *(temp+1) - '0' > 9) {
	  if(*(temp+1) != '.' || temp != head)
	    return false;
	}
      } else if(*temp == 'e' || *temp == 'E') {
	e++;
    if(e > 1 || num == 0)
        return false;
    if(temp == head)
        return false;
	if((*(temp+1) - '0' >= 0 && *(temp+1) - '0' <= 9 )
	   || *(temp+1) == '-' || *(temp+1) == '+'){
	  continue;
	}else{
	  return false;
	}
      } else if(*temp == '.') {
    	dot++;
        if(e > 0 || dot > 1) {
            return false;
        }
        //if(*(temp+1) - '0' < 0 || *(temp+1) - '0' > 9)
        //    return false;
    	if(temp != head) {
    	  if((*(temp-1)- '0' >= 0 && *(temp-1)- '0' <= 9 )
    	     || *(temp-1) == '-' || *(temp-1) == '+') {
    	    continue;
    	  }else
    	    return false;
    	}
      } else {
	return false;
      }  
    } else
        num++;
  }
  if(*temp - '0' < 0 || *temp - '0' > 9) {
    if(*temp == '.') {
      dot++;
      if(e > 0) return false;
    }
    if(*temp != '.' || dot > 1 || (*head == '.' && *end == '.'))
      return false;
    if(*(temp-1)- '0' < 0 || *(temp-1)- '0' > 9) {
      return false;
    }
  }
  return true;
}

};
