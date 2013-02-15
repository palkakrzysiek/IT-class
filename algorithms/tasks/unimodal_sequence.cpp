bool checkIfSequenceIsUnimodal(int *T, int N){
    /* 
     * IC: T is an array of integers, N is number of elements
     * PC: return true if sequence is unimodal or false otherwise 
     * TC: O(N)
     * SC: O(1)
     */
    if(N < 3)
        return false; // ciąg musi mieć co najmniej 3 elementy, żeby na początku malał, później rósł, środkowy element będzie wtedy minimum lokalnym
    int position = 1;
    int lastValue = T[0];
    while (T[position] < lastValue){ // dopóki kolejna wartość jest mniejsza od poprzedniej zwiększaj licznik
        lastValue = T[position];
        position++;
    }

    // w tym momencie licznik znajduje się na minimalnej wartości
    // teraz trzeba sprawdzić, czy została w nim choć jeden element do sprawdzenia - jeśli nie, to ciąg w całym swoim
    // zakresie byłby malejący, kolejna pętla nie zwiększyła by licznika i byłby on na ostatnim elemencie, więc warunek,
    // który jest na końcu funkcji byłby spełniony
    
    if(N - position < 1) // jeśli nie ma jeszcze choć jednego elementu
        return false;

    while (T[position] > lastValue){ // dopóki kolejna wartość jest większa od poprzedniej zwiększaj licznik
        lastValue = T[position];
        position++;
    }
    if (position == N - 1) // jeśli licznik znajduje się na ostatnim elemencie zwróć prawdę - oznacza to, że nie było więcej niż jednego minimum lokalnego - gdyby ciąg znowu zaczął maleć, to licznik nie zwiększałby się
        return true;
    else
        return false;
}
