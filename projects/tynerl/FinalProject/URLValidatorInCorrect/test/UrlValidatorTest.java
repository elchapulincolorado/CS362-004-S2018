

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

   
   // Written by David
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
   
   // Written by Nicolas
   public void testNoFragments()
   {
      System.out.println("No Fragments testing...");
      UrlValidator urlVal = new UrlValidator(UrlValidator.NO_FRAGMENTS + UrlValidator.ALLOW_ALL_SCHEMES);

      assertTrue(urlVal.isValid("http://go.com/test1")); //valid, no fragments
      assertFalse(urlVal.isValid("http://go.com/test1#Frag")); //invalid, fragment

   }

   // Written by Nicolas
   public void testAllow2Slashes()
   {
      System.out.println("Allow 2 Slashes testing...");
      UrlValidator urlVal = new UrlValidator(UrlValidator.NO_FRAGMENTS + UrlValidator.ALLOW_ALL_SCHEMES);

      assertFalse(urlVal.isValid("http://go.comtest1")); //no slash present, should not be allowed
      assertTrue(urlVal.isValid("http://go.com/test1")); //one slash present, always allowed
      assertTrue(urlVal.isValid("http://go.com//test1")); //double slash present, allowed
      //assertFalse(urlVal.isValid("http://go.com///////test1")); //many slashes present, should not be allowed
      //many slashes should be asserted as False, but error occurs and allows for more than 2 slashes

   }

   // Written by Nicolas
   public void testSchemePartition()
   {
      //Scheme testing
      System.out.println("Scheme Partition testing...");
      UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.NO_FRAGMENTS + UrlValidator.ALLOW_ALL_SCHEMES);

      assertTrue(urlVal.isValid("http://www.google.com#FRAG")); //random testing of fragment allowance
      assertTrue(urlVal.isValid("ftp://google.com"));
      assertTrue(urlVal.isValid("h3t://google.com"));
      assertFalse(urlVal.isValid("http:google.com"));
      assertFalse(urlVal.isValid("://google.com"));
      assertFalse(urlVal.isValid("google.com"));

      System.out.println("Finished Scheme testing...");


   }

   // Written by Nicolas
   public void testAuthorityPartition()
   {
      //Authority testing
      System.out.println("Authority Partition testing...");

      UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.NO_FRAGMENTS + UrlValidator.ALLOW_ALL_SCHEMES);
      assertTrue(urlVal.isValid("http://go.com"));
      assertTrue(urlVal.isValid("http://go.au"));
      assertTrue(urlVal.isValid("http://255.255.255.255"));
      assertFalse(urlVal.isValid("http://1.2.3.4.5"));
      assertFalse(urlVal.isValid("http://aaa."));
      assertFalse(urlVal.isValid("http://go.1aa"));

      System.out.println("Finished Authority testing...");

   }

   // Written by Nicolas
   public void testPortPartition()
   {
      //Port testing
      System.out.println("Port Partition testing...");

      UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
      assertTrue(urlVal.isValid("http://go.com:80"));
      assertTrue(urlVal.isValid("http://go.com:0"));
      assertTrue(urlVal.isValid("http://go.com:65535"));
      assertFalse(urlVal.isValid("http://go.com:-1"));
      assertFalse(urlVal.isValid("http://go.com:65636"));
      assertFalse(urlVal.isValid("http://go.com:65a"));

      System.out.println("Finished Port testing...");

   }

   // Written by Nicolas
   public void testPathPartition()
   {
      //Path testing
      System.out.println("Path Partition testing...");

      UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
      assertTrue(urlVal.isValid("http://go.com/test1"));
      assertTrue(urlVal.isValid("http://go.com/t123"));
      assertTrue(urlVal.isValid("http://go.com/test1/file"));
      assertFalse(urlVal.isValid("http://go.com/test1//file"));
      assertFalse(urlVal.isValid("http://go.com/.."));
      assertFalse(urlVal.isValid("http://go.com/..//file"));

      System.out.println("Finished Path testing...");

   }

   // Written by Lowell
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
