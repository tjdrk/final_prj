class Othello {
    private:
        int stage[8][8];
        int turn;
    
    public:
        Othello();
        int get_turn();
        void change_turn();
        bool mark_check(int row, int col, int turn);
        void put_mark(int row, int col, int turn);
        bool game_check(int turn);
        void print_stage();
        int get_score1();
        int get_score2();
};
