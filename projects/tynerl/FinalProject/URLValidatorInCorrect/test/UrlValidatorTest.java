

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
      //changed: see bug 1
      //String[] schemes = {"http","https"};

      UrlValidator validator = new UrlValidator(UrlValidator.ALLOW_ALL_SCHEMES);
      if (validator.isValid("https://www.google.com")) {
         System.out.println("url is valid");
      } else {
         System.out.println("url is invalid");
      }
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
      List<String> validStrings = new ArrayList<>();
      validStrings.add("http://www.google.com");
      validStrings.add("https://www.google.com");

      List<String> invalidStrings = new ArrayList<>();
      invalidStrings.add("");
      invalidStrings.add("google");
      invalidStrings.add(".com");
      invalidStrings.add("www.google.com");

      List<String> failures = new ArrayList<>();

      UrlValidator validator = new UrlValidator();

      // test valid strings
      for (String validString : validStrings) {
         boolean isValidResult = validator.isValid(validString);
         if(!isValidResult) {
            // is expected to be valid
            failures.add(validString);
         }
      }

      // test invalid strings
      for (String invalidString : invalidStrings) {
         boolean isValidResult = validator.isValid(invalidString);
         if (isValidResult) {
            // not expected to be valid
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

      // fails the test if any failures are present
      assertTrue(failures.isEmpty());
      // done
   }
}
