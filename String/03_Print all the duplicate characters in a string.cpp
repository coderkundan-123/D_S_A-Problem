/****** GFG Problem hai **********/
// JavaScript Code to print duplicate characters 
// and their counts using Sorting 
/* TC: O(n log n)
   SC: O(1)
*/

// Function to print duplicate characters with their count
function printDuplicates(s) {

    // Convert string to array and sort to group same characters
    s = s.split('').sort().join('');

    // Traverse the sorted string to count duplicates
    let i = 0;
    while (i < s.length) {

        let count = 1;

        // Count occurrences of current character
        while (i + count < s.length && s[i] === s[i + count]) {
            count++;
        }

        // If count > 1, print the character and its count
        if (count > 1) {
            console.log(["" + s[i] + "", count]);
        }

        // Move to the next different character
        i += count;
    }
}

// Driver Code
let s = "geeksforgeeks";

printDuplicates(s);

OUT PUT 
['e', 4], ['g', 2], ['k', 2], ['s', 2], 
