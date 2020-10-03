import java.util.*;

/* An anagram is a word or phrase made by transposing the letter of another workd or phrase*/

/* This program figures out whether one String is anagram of another String or not.*/
/* The program ignores whitespace and punctuation or any other Special Characters*/

public class Anagram {

    public static boolean areAnagrams(String s1 , String s2) {
        //To remove all the special Characters and punctuation etc..
        String workingCopy1 = removeJunk(s1);
        String workingCopy2 = removeJunk(s2);

        //Can also convert to uppercase,,, Just for comparing two strings
        workingCopy1 = workingCopy1.toLowerCase();
        workingCopy2 = workingCopy2.toLowerCase();

        //Sort the strings
        workingCopy1 = sort(workingCopy1);
        workingCopy2 = sort(workingCopy2);

        //comparing the Strings using .equals() method and returning the value.
        return workingCopy1.equals(workingCopy2);
    }

    //Method to remove all the special characters,white-spaces,etc.
    protected static String removeJunk(String s) {
        int i,len = s.length();
        //Creating A StringBuilder Object to apply modifications to the string.
        StringBuilder dest = new StringBuilder(len);
        char c;


        for(i = len-1; i>=0;i--) {
            c = s.charAt(i);
            //appending the character to the stringbuilder object if it's an alphabet.
            if(Character.isLetter(c)) {
                dest.append(c);
            }
        }

        return dest.toString(); //Converting to a string and returning value
    }

    //Method to Sort the string
    protected static String sort(String s) {
        char[] charArray = s.toCharArray(); //Converting the String into a CharArray

        Arrays.sort(charArray); //Simple pre-defined sorting method in java.util.Arrays class. the sorting is In-Place.

        return new String(charArray);	//Returning the sorted charArray as String.
    }


    //	Driver method
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter String 1: ");
        String s1 = sc.nextLine();
        System.out.print("\nEnter String 2: ");
        String s2 = sc.nextLine();

//One example for Anagram
//	s1 = "Cosmo and Laine:";
//	s2 = "Maid, Clean soon!";

        System.out.println("Entered Strings are: \n\n 1> " + s1 + "\n 2> " + s2 + "\n" );
        if(areAnagrams(s1,s2)) System.out.println("Anagrams!!");
        else System.out.println("Not Anagrams :(");

        sc.close();
    }

}
