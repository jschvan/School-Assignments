package QuestionThree;

public class MyOnlyObject
{
    private static MyOnlyObject instance;//DO NOT EDIT THIS LINE
    private Integer amount;//DO NOT EDIT THIS LINE

    //TODO: Create the constructor for MyOnlyObject. It doesn't need to do anything; there's no default value for amount.

    //put constructor here
    private MyOnlyObject(){

    }

    /*TODO:
     * Create and implement the static function called "getInstance()" used for returning the instance of MyOnlyObject.
     * In the "Lazy initialization" implementation of the Singleton Pattern, getInstance is where the singleton object
     * is initialized using the constructor.
     */

    //put getInstance here
    public static MyOnlyObject getInstance(){
        if(instance == null){
            instance = new MyOnlyObject();
        }
        return instance;
    }

    //TODO: Create and implement a function called getAmount(). It's a typically getter for the amount field.
    // There is no need to check that amount isn't null

    //put getAmount here

    public Integer getAmount() {
        return amount;
    }

    //TODO: Create and implement a function called setAmount(). It's a typically setter for the amount field.
    // No input-validation needed.

    //put setAmount here
    public void setAmount(int input){
        amount = input;
    }

}
