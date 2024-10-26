package QuestionOne;

public class questionOneDriver
{
    public static void main(String[] args)
    {
        /*TODO
         * create an instance of the generic link list. Call it whatever you want. This instance of the linked list should
         * hold characters.
         */
        genericLL<Character> ll = new genericLL<>();


        /*TODO
         * Once you've created your LL, populate it with every other letter in the alphabet ('a', 'c', 'e', 'g', 'i',
         * 'k', 'm', 'o', 'q', 's', 'u', 'w', 'y').
         */
        ll.insert('a');
        ll.insert('c');
        ll.insert('e');
        ll.insert('g');
        ll.insert('i');
        ll.insert('k');
        ll.insert('m');
        ll.insert('o');
        ll.insert('q');
        ll.insert('s');
        ll.insert('u');
        ll.insert('w');
        ll.insert('y');


        /*TODO
         * print the Linked List.
         */
        ll.print();


        /*TODO
         * Check and see if the letters 's', 'b', or 'o' are in the list. If they are, remove them from the list.
         * If they're not, don't do anything.
         *
         * HINT: This is not a circular linked list. This means that once you hit the end of the list, you need to
         * reset the curr pointer back to the start of the linked list.
         */
        if(ll.isContained('s')){
            ll.goToNodeWithData('s');
            ll.deleteCurr();
        }
        if(ll.isContained('b')){
            ll.resetCurr();;
            ll.goToNodeWithData('b');
            ll.deleteCurr();
        }
        if(ll.isContained('o')){
            ll.resetCurr();;
            ll.goToNodeWithData('o');
            ll.deleteCurr();
        }


        /*TODO
         * print the Linked List.
         */

        ll.print();


        /*TODO
         * Find the character 'i' in the linked list and set it to 'z'
         */
        ll.goToNodeWithData('i');
        ll.setCurr('z');


        /*TODO
         * finally, print the Linked List again.
         */
        ll.print();

    }
}
