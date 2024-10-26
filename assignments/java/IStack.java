package lab4;

import java.lang.reflect.Array;
import java.util.ArrayList;

/**
 * A generic stack interface. A stack is a collection of elements, with two main principal operations:
 * push, which adds an element to the collection, and pop, which removes the most recently added element that was not yet removed.
 * The order in which elements come off a stack gives rise to its alternative name, LIFO (last in, first out).
 * Additionally, a peek operation may give access to the top without modifying the stack.
 * The stack is a linear data structure, and the order of elements is maintained by the stack.
 *
 * @defines size: max number of elements the stack can hold
 *          self: the stack
 *
 * @constraints size > 0 AND 0 <= |self| <= size
 *
 * @initialization_ensures an empty stack is created with a max number of elements the stack can hold equal to size
 */
public interface IStack<T>
{

    /**
     * Get the elements of the stack.
     *
     * @pre none
     *
     * @post getElements = self AND self = #self AND #size = #size
     */
    public ArrayList<T> getElements();

    /**
     * Get the capacity of the stack.
     *
     * @return the capacity of the stack
     *
     * @pre none
     *
     * @post getCapacity = size AND self = #self AND #size = #size
     */
    public int getCapacity();

    /**
     * Push a value into the stack. If the stack is full, the longest-standing element will be removed to make space.
     *
     * @param value the value to be pushed into the stack
     *
     * @pre none
     *
     * @post |self| = |self| + 1 AND self = [#self with the item pushed into the stack where if the stack is full,
     * the longest-standing element is removed from the stack] AND #size = #size
     *
     */
    public default void push(T value){
        ArrayList<T> elements = getElements();
        if(getSize() < getCapacity()) {
            elements.add(getSize(), value);
        }

        else if(getSize() == getCapacity()){
            elements.remove(0);
            elements.add(getSize(), value);
        }
    }

    /**
     * Pop a value from the stack.
     *
     * @return the value popped from the stack
     *
     * @pre elements.size() > 0
     *
     * @post pop = [The item last pushed into the stack] AND |self| = |self| - 1 AND self = [#self except
     * the item last pushed into the stack has been removed] AND #size = #size
     */
    public default T pop() {
        ArrayList<T> elements = getElements();
        T return_value = elements.get(getSize()-1);
        elements.remove(getSize()-1);
        return return_value;
    }

    /**
     * Peek the value from the top of the stack.
     *
     * @return the last pushed-in value of the stack
     *
     * @pre elements.size() > 0
     *
     * @post peek = [The item last pushed into the stack] AND self = #self AND #size = #size
     */
    public default T peek() {
        ArrayList<T> elements = getElements();
        return elements.get(getSize()-1);
    }

    /**
     * Get the size of the stack. The size of the stack is defined as the number of elements in the stack.
     *
     * @return the size of the stack
     *
     * @pre none
     *
     * @post getSize = |self| AND self = #self AND #size = #size
     */
    public default int getSize(){
        ArrayList<T> elements = getElements();
        return elements.size();
    }
}
