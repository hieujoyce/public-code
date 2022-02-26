package de06CuoiKi;

public class Book {
    private int id;
    private String authors;
    private String title;
    Category category;

    public Book(int id, String authors, String title, Category category) {
        this.id = id;
        this.authors = authors;
        this.title = title;
        this.category = category;
    }

    public Book() {
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getAuthors() {
        return authors;
    }

    public void setAuthors(String authors) {
        this.authors = authors;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public Category getCategory() {
        return category;
    }

    public void setCategory(Category category) {
        this.category = category;
    }

    @Override
    public String toString() {
        return "Id: " + id + ", Authors: " + authors + ", Title: " + title + ", Category: " + category.getType();
    }
    
    
    
}
