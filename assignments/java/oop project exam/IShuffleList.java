package cpsc2150.listDec;

import java.util.List;
import java.util.Random;

public interface IShuffleList<T> extends List<T>{


    /**
     * This function randomly picks two positions in a list
     * and swaps them, it repeats this swaps amount of times
     *
     * @param swaps the amount of times this function repeats
     * randomly swapping its elements
     *
     * @pre [list is not empty]
     *
     * @post [list contains elements that have been swapped
     * swaps amount of times]
     */
    default void shuffle(int swaps){
        for (int i = 0; i < swaps; i++) {
            Random rand = new Random();
            int rand_num_1 = rand.nextInt(this.size());
            int rand_num_2 = rand.nextInt(this.size());
            swap(rand_num_1, rand_num_2);
        }
        
    };




    /**
     * This function exchanges values at two positions
     *
     * @param i the position of the first element to be swapped
     * @param j the position of the second element to be swapped
     *
     * @pre list[i] != NULL AND list[j] != NULL
     *
     * @post list[i] = [the element that was in list[j]] AND
     * list[j] = list[i]
     */
    default void swap(int i, int j){
        T temp = this.get(i);
        this.set(i, this.get(j));
        this.set(j, temp);
    };


}
