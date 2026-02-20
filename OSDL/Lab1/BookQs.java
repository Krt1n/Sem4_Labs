package Lab1;
class Book {
    private int bookId;
    private String bookName;
    private Boolean availability;
    private double price;
    private String authorName;

    public void setBookID(int bookId){
        this.bookId = bookId;
    }
    public void setbookName(String bookName){
        this.bookName=bookName;
    }
    public void setAvail(Boolean availability){
        this.availability=availability;
    }
    public void setPrice(double price){
        if(price>0){
            this.price = price;
        }
        else{
            System.out.println("Invalid Price. Price should be positive");
        }
    }
    public void setAuthor(String authorName){
        this.authorName = authorName;
    }
    public int getBookID(){
        return bookId;
    }
    public String getbookName(){
        return bookName;
    }
    public Boolean getAvail(){
        return availability;
    }
    public double getPrice(){
        return price; 
    }
    public String getAuthor(){
        return authorName;
    }
}
public class BookQs {
    public static void main(String args[]){
        Book b = new Book();
        b.setBookID(1);
        b.setbookName("Harry Potter");
        b.setAuthor("JK Rowling");
        b.setPrice(100);
        b.setAvail(true);
        
        System.out.println("Book Details:");
        System.out.println("----------------");
        System.out.println("Book ID:" + b.getBookID());
        System.out.println("Book Name:" + b.getbookName());
        System.out.println("Book Author:" + b.getAuthor());
        System.out.println("Price:" + b.getPrice());
        System.out.println("Availablity:" + b.getAvail());
    }
}

