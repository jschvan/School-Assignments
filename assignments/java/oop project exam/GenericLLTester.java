package QuestionTwo;

import QuestionOne.genericLL;
import org.junit.Test;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

public class GenericLLTester
{
    private genericLL<String> genericLLFactory()
    {
        return new genericLL<String>();
    }

    private genericLL<String> createNonEmptyGenericLL()
    {
        genericLL<String> genLL = genericLLFactory();
        genLL.insert("Cat");
        genLL.insert("Fish");
        genLL.insert("Cactus");
        return genLL;
    }

    @Test(timeout=200)
    public void testGetCurrent_Non_Empty_List_Cat()
    {
        genericLL<String> test_list = createNonEmptyGenericLL();
        String expected = "Cat";
        String observed = test_list.getCurr();
        assertEquals(expected, observed);
    }

    @Test(timeout=200)
    public void testGoToNext_Non_Empty_List_To_Fish()
    {
        genericLL<String> test_list = createNonEmptyGenericLL();
        String expected = "Fish";
        test_list.goToNext();
        String observed = test_list.getCurr();
        assertEquals(expected, observed);

    }

    @Test(timeout=200)
    public void testIsContained_Non_Empty_List_Fish_True()
    {
        genericLL<String> test_list = createNonEmptyGenericLL();
        String expected = "Fish";
        assert(test_list.isContained(expected));
    }

    @Test(timeout=200)
    public void testIsContained_Non_Empty_List_Monkey_False()
    {
        genericLL<String> test_list = createNonEmptyGenericLL();
        String expected = "Monkey";
        assert(!test_list.isContained(expected));

    }

    @Test(timeout=200)
    public void testSetCurrent_Non_Empty_List_Cat_To_Cow()
    {
        genericLL<String> test_list = createNonEmptyGenericLL();
        test_list.setCurr("Cow");
        String expected = "Cow Fish Cactus";
        String observed = "";
        observed = observed + test_list.getCurr() + " ";
        test_list.goToNext();
        observed = observed + test_list.getCurr() + " ";
        test_list.goToNext();
        observed = observed + test_list.getCurr();

        assertEquals(expected, observed);
    }

    @Test(timeout=200)
    public void testInsert_Non_Empty_List()
    {
        genericLL<String> test_list = createNonEmptyGenericLL();
        String expected = "Dog";
        test_list.insert("Dog");
        test_list.goToTail();
        String observed = test_list.getCurr();
        assertEquals(expected, observed);
    }

    @Test(timeout=200)
    public void testInsert_Empty_List_Monkey()
    {
        genericLL<String> test_list = new genericLL<>();
        String expected = "Monkey";
        test_list.insert("Monkey");
        String observed = test_list.getCurr();
        assertEquals(expected, observed);
    }

    @Test(timeout=200)
    public void testDelete_Non_Empty_List_Delete_Last_Item_In_List()
    {
        genericLL<String> test_list = createNonEmptyGenericLL();
        test_list.goToTail();
        test_list.deleteCurr();

        String expected = "Fish";
        String observed = test_list.getCurr();

        assertEquals(expected, observed);
    }


}
