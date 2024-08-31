import React from "react";
import { useState } from "react";

import Footer from "./components/Footer";
import ProductsList from "./components/ProductsList";
import FormData from "./components/FormData";

import './styles/App.css';
import 'bootstrap/dist/css/bootstrap.min.css';
import SumComponent from "./Sum";


const App = () => {
  const [hasChanged, setHasChanged] = useState(false);

  const updatePorducts = () => {
    setHasChanged(!hasChanged);
  }

  return (
    <>
      <div className="container my-5">
        <h2 className="related-products-title">Related Products</h2>
        <ProductsList hasChanged={hasChanged} />
      </div>
      <FormData updatePorducts={updatePorducts}/>
      <Footer />
    </>

  );
}

export default App;
