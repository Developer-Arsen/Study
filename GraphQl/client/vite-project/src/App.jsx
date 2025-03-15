import { gql, useQuery } from "@apollo/client";
import "./App.css";
import useCounter from "./useCounter";

const GET_BOOKS = gql`
  {
    books {
      id
      title
      price
      author {
        id
        name
        utyu
      }
    }
  }
`;

function App() {
  const { loading, data, error } = useQuery(GET_BOOKS);

  const { count, increment, decrement } = useCounter(0);

  return (
    <>
      <h2>Counter: {count}</h2>
      <button onClick={increment}>Increment</button>
      <button onClick={decrement}>Decrement</button>
      {loading && <p>Loading</p>}
      {error && <p>{error.message}</p>}
      {data?.books.map((book, index) => (
        <>
          <p key={index}>
            {book.id} {book.title}{" "}
          </p>
        </>
      ))}
    </>
  );
}

export default App;
