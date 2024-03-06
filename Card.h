class Card{
    public:
        Card *next;
        int value;
        Card(int cardNum) {value = cardNum; next = nullptr;}
};