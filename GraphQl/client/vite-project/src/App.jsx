import { gql, useQuery } from '@apollo/client';
import './App.css'

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
  const {loading, data, error} = useQuery(GET_BOOKS);

  console.log(error.message);
  


  return (
    <>
    {loading && <p>Loading</p>}
    {error && <p>{error.message}</p>}
      { data?.books.map((book, index) => 
          <>
          <p key={index}>{book.id} {book.title} </p>
          </>
      ) }    
    </>
  )
}

export default App
