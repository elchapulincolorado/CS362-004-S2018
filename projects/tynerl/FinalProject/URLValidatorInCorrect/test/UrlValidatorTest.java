

import junit.framework.TestCase;

import java.util.ArrayList;
import java.util.List;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!

public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   
   public void testManualTest()
   {
//You can use this function to implement your manual testing	   
	   
   }
   
   
   public void testYourFirstPartition()
   {
	 //You can use this function to implement your First Partition testing	   

   }
   
   public void testYourSecondPartition(){
		 //You can use this function to implement your Second Partition testing	   

   }
   //You need to create more test cases for your Partitions if you need to 
   
   public void testIsValid() {
      List<String> validStrings = new ArrayList<>(); // {"google.com", "www.google.com", "http://www.google.com"}
      validStrings.add("google.com");
      validStrings.add("www.google.com");
      validStrings.add("http://www.google.com");

      List<String> invalidStrings = new ArrayList<>();
      invalidStrings.add("");
      invalidStrings.add("google");
      invalidStrings.add(".com");

      List<String> failures = new ArrayList<>();

      UrlValidator validator = new UrlValidator();

      // test valid strings
      for (String validString : validStrings) {
         if(!validator.isValid(validString)) {
            failures.add(validString);
         }
      }

      // test invalid strings
      for (String invalidString : invalidStrings) {
         if (validator.isValid(invalidString)) {
            failures.add(invalidString);
         }
      }

      // print out failures
      for (String failure : failures) {
         if (validStrings.contains(failure)) {
            System.out.println("Was supposed to pass UrlValidator.isValid() but did not: " + failure);
         }
         if (invalidStrings.contains(failure)) {
            System.out.println("Was supposed to fail UrlValidator.isValid() but it passed: " + failure);
         }
      }
      // done
   }
   


}
