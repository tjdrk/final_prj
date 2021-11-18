class Othello {
    private:
        int stage[8][8];                              // 8x8 말판
        int turn;                                     // 플레이어의 차례
    
    public:
        Othello();                                    // constructor
        int get_turn();                               // 누구의 턴인지 출력
        void change_turn();                           // 턴 종료 및 턴 바꿈
        bool mark_check(int row, int col, int turn);  // 해당 위치에 말을 놓는 것이 유효한지 체크
        void put_mark(int row, int col, int turn);    // 해당 위치에 말을 놓고 기존의 말들 상태 변경
        bool game_check(int turn);                    // 해당 턴의 플레이어가 말을 놓을 곳이 있는지 체크
        void print_stage();                           // 현재 말판의 상태를 출력
        int get_score1();                             // 플레이어 1의 스코어 출력
        int get_score2();                             // 플레이어 2의 스코어 출력
};
