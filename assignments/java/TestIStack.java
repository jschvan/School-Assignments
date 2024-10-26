package tests;
import lab4.GenericStack;
import lab4.IStack;
import org.junit.Test;
import static org.junit.Assert.*;

public class TestIStack {

    @Test
    public void testPush_1_2_3(){
        IStack<Integer> stack = new GenericStack<>(3);
        stack.push(1);
        stack.push(2);
        stack.push(3);
        String observed = stack.toString();
        String expected = "stack: [1, 2, 3]";
        assertEquals(expected, observed);
    }

    @Test
    public void testPush_1_2_3_4(){
        IStack<Integer> stack = new GenericStack<>(3);
        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(4);
        String observed = stack.toString();
        String expected = "stack: [2, 3, 4]";
        assertEquals(expected, observed);
    }

    @Test
    public void testPeek_fullStack_Output4(){
        IStack<Integer> stack = new GenericStack<>(3);
        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(4);
        Integer observedItem = stack.peek();
        Integer expectedItem = 4;
        assertEquals(expectedItem, observedItem);
        String observed = stack.toString();
        String expected = "stack: [2, 3, 4]";
        assertEquals(expected, observed);
    }

    @Test
    public void testPop_fullStack_Output7(){
        IStack<Integer> stack = new GenericStack<>(3);
        stack.push(1);
        stack.push(3);
        stack.push(5);
        stack.push(7);
        Integer observedItem = stack.pop();
        Integer expectedItem = 7;
        assertEquals(expectedItem, observedItem);
        String observed = stack.toString();
        String expected = "stack: [3, 5]";
        assertEquals(expected, observed);
    }

    @Test
    public void testGetSize_Output2(){
        IStack<Integer> stack = new GenericStack<>(3);
        stack.push(1);
        stack.push(3);
        Integer observedItem = stack.getSize();
        Integer expectedItem = 2;
        assertEquals(expectedItem, observedItem);
        String observed = stack.toString();
        String expected = "stack: [1, 3]";
        assertEquals(expected, observed);
    }

}
