package de04CuoiKi;

import java.util.ArrayList;

public class Dictionary {
    static ArrayList<Word> di = new ArrayList<>();
    static {
        di.add(new Word("time", "thời gian"));
        di.add(new Word("year", "năm"));
        di.add(new Word("people", "con người"));
        di.add(new Word("way", "con đường"));
        di.add(new Word("day", "ngày"));
        di.add(new Word("man", "đàn ông"));
        di.add(new Word("thing", "sự vật"));
        di.add(new Word("group", "nhóm"));
        di.add(new Word("hand", "bàn tay"));
        di.add(new Word("home", "nhà"));
    }
    
}
