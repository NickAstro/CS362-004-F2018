

import junit.framework.TestCase;
import org.junit.Test;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!

public class UrlValidatorTest extends TestCase {

   public UrlValidatorTest(String testName) {
      super(testName);
   }

   @Test
   public void testManualTest()
   {
      boolean result = true;
      UrlValidator valid = new UrlValidator(null, null, 0);

      ResultPair[] manualTests = {new ResultPair("://docs.google.com/",false),
              new ResultPair("https://docs.google.com/", true),
              new ResultPair("httt://docs.google.com/", false),
              new ResultPair("httphttps://docs.google.com/", false),
              new ResultPair("hhttp>//www.google.com", false),
              new ResultPair("http://.com/", false),
              new ResultPair("https://github.com", true),
              new ResultPair("http://178.128.190.13", true),
              new ResultPair("https://github.com.github.com//", false),
              new ResultPair("https://github.gggg", false),
              new ResultPair("http://1.1.0.3", false),
              new ResultPair("https://github.com:", true),
              new ResultPair("http://178.128.190.13:3000/", true),
              new ResultPair("https://github.com:-15", false),
              new ResultPair("https://github.com::..", false),
              new ResultPair("https://sourceforge.net/", true),
              new ResultPair("https://html.spec.whatwg.org/multipage/", true),
              new ResultPair("https://twitter.com///vinnyasa", false),
              new ResultPair("https://www.linkedin.com/in/_/vinnyasa/", false)
      };

      for(int testcase = 0; testcase < manualTests.length; testcase++) {
         result = valid.isValid(manualTests[testcase].item);
         if(result != manualTests[testcase].valid) {
            System.out.print("URL Doesn't Match expected result: " + manualTests[testcase].item + "      ...");
            System.out.print("Expected: " + manualTests[testcase].valid + ", actual: " + result + "\n");

         }
         else {
            System.out.print("URL Matches expected value: " + manualTests[testcase].item + "\n");
         }
      }

   }


   /**
    * Partition testing - this is the test for our first partiton: Scheme
    * Will test the scheme component of a URL
    * **/

   public void testFirstPartition() {
      boolean result = true;
      UrlValidator valid = new UrlValidator(null, null, 0);

      ResultPair[] schemePart = {new ResultPair("//oregonstate.edu/", false),
              new ResultPair("https://www.oneplus.com/6", false),
              new ResultPair("httt://docs.google.com/", false),
              new ResultPair("htpp://oregonstate.edu/", false),
              new ResultPair("http>//www.linkedin.com", false),
              new ResultPair("httud//osu-cs.slack.com", true)
      };
      for(int testcase=0; testcase < schemePart.length; testcase++) {
         result = valid.isValidScheme(schemePart[testcase].item);
         if (result != schemePart[testcase].valid) {
            System.out.print("URL Doesn't Match valid: " + schemePart[testcase].item + "\n");
         } else {
            System.out.print("URL Matches Return Value: " + schemePart[testcase].item + "\n");
         }

      }
   }


   /**
    * Partition testing - this is the test for our second partition: Authority
    * Will test the authority component of a URL
    * **/

   public void testSecondPartition() {

      boolean result = true;
      UrlValidator valid = new UrlValidator(null, null, 0);

      ResultPair[] authorityPart = {new ResultPair("http://.com/", false),
              new ResultPair("https://docs.microsoft.com", true),
              new ResultPair("http://178.128.190.13", true),
              new ResultPair("http://oregonstate.eeeeee", false),
              new ResultPair("http://oregonstate", false),
              new ResultPair("https://osu-cs.slack.com", true),
              new ResultPair("https://www.google.ca", true),
              new ResultPair("https://www.google.mx", true)
      };

      for (int testcase=0; testcase < authorityPart.length; testcase++) {
         result= valid.isValid(authorityPart[testcase].item);
         if (result != authorityPart[testcase].valid) {
            System.out.print("URL Doesn't Match valid: " + authorityPart[testcase].item + "\n");
         } else {
            System.out.print("URL Matches Return Value: " + authorityPart[testcase].item + "\n");
         }
      }

   }

   /**
    * Partition testing - this is the test for our third partition: Port
    * Will test the port component of a URL when it exists or if it does not.
    * **/

   public void testThirdPartition() {
      boolean result = true;
      UrlValidator valid = new UrlValidator(null, null, 0);

      ResultPair[] portPart = {new ResultPair("https://github.com:", true),
              new ResultPair("http://178.128.190.13:3000/", true),
              new ResultPair("https://github.com:-15", false),
              new ResultPair("https://github.com::..", false)
      };

      for (int testcase=0; testcase < portPart.length; testcase++) {
         result = valid.isValid(portPart[testcase].item);
         if (result != portPart[testcase].valid) {
            System.out.print("URL Doesn't Match valid: " + portPart[testcase].item + "\n");
         } else {
            System.out.print("URL Matches Return Value: " + portPart[testcase].item + "\n");
         }
      }

   }

   /**
    * Partition testing - this is the test for our fourth partition: Path
    * Will test the path component of a URL
    * **/

   public void testFourthPartition()
   {
      boolean result = true;
      UrlValidator valid = new UrlValidator(null, null, 0);

      ResultPair[] pathPart = {new ResultPair("https://dropbox.com/", true),
              new ResultPair("https://developer.mozilla.org/en-US/docs/Learn/Common_questions/What_is_a_URL", true),
              new ResultPair("https://getbootstrap.com/docs/4.0/components/buttons/", true),
              new ResultPair("https://app.clickup.com////1228508", false),
              new ResultPair("https://www.linkedin.com/in/_/hp/", false)
      };

      for(int testcase = 0; testcase < pathPart.length; testcase++) {
         result = valid.isValid(pathPart[testcase].item);
         if (result != pathPart[testcase].valid) {
            System.out.print("URL Doesn't Match valid: " + pathPart[testcase].item + "\n");
         } else {
            System.out.print("URL Matches Return Value: " + pathPart[testcase].item + "\n");
         }
      }
   }

   /**
    * Partition testing - this is the test for our first partition: Query
    * Will test the query component of a URL
    * **/

   public void testYourFifthPartition(){
      //You can use this function to implement your Second Partition testing

      boolean result = true;
      UrlValidator valid = new UrlValidator(null, null, 0);

      ResultPair[] queryPart = {new ResultPair("https://www.google.com/search?q=test+queries&oq=test+queries", true),
              new ResultPair("https://www.amazon.com/b/ref=CMDW18_GW_Desk_Dashboard_EN?node=5550342011&pf_rd_p=4e14b528-bdb5-4ee2-b21b-d6ab82779a72&pf_rd_r=JD7B9SZ5S658NCPXMSPK", true),
              new ResultPair("http://www.example.com/some-page.asp?articleid=232", true)
      };

      for(int testcase = 0; testcase < queryPart.length; testcase++) {
         result = valid.isValid(queryPart[testcase].item);
         if (result != queryPart[testcase].valid) {
            System.out.print("URL Doesn't Match valid: " + queryPart[testcase].item + "\n");
         } else {
            System.out.print("URL Matches Return Value: " + queryPart[testcase].item + "\n");
         }
      }

   }


   public void testIsValid()
   {
      //You can use this function for programming based testing

   }



}



