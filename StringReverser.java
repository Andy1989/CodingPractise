public class StringReverser {
  public StringReverser(String str) {
    if (str == null) {
      throw new IllegalArgumentException("Null value!");
    }
    this.originalString = str;
  }
  
  public String reverse() {
    if (reversedString == null) {
      char[] charArr = originalString.toCharArray();
      int start = 0, end = charArr.length;
      while (start < end) {
        char tmp = charArr[start];
        charArr[start++] = charArr[end];
        charArr[end--] = tmp;
      }
      reversedString = new String(charArr);
    }
    return reversedString;
  }
  
  private String reversedString;
  private String originalString;
}
