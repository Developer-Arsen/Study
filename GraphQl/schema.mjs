import { buildSchema } from "graphql"

const authors = [
    {id : 101, name: "Ars"},
    {id : 102, name: "Lus"},
]

const books = [
    {id : 1, title: "Hamlet", price: 10, author: authors[0]},
    {id : 2, title: "Gegham", price: 20, author: authors[0]},
    {id : 3, title: "No exit", price: 30, author: authors[1]},
]


export const schema = buildSchema(`
    type Query {
        books: [Book]
        authors: [Author]
        book(id:Int): Book
    }

    type Author {
        id:Int
        name: String
    }    
    type Book {
        id: Int
        title: String
        price: Float
        author: Author
    }
`)


export const resolvers = {
    books: () => books,
    authors: () => authors,
    book: ({id}) => books.find((el) => el.id === id),
}