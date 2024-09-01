import React, { useState } from "react";
import Footer from "./components/Footer";
import ProductsList from "./components/ProductsList";
import ProductFormData from "./components/ProductFormData";

import './styles/App.css';
import 'bootstrap/dist/css/bootstrap.min.css';

const App = () => {
  const [hasChanged, setHasChanged] = useState(false);

  const updateProducts = () => {
    setHasChanged(!hasChanged);
  }

  return (
    <>
      <div className="container my-5">
        <h2 className="related-products-title">Related Products</h2>
        <ProductsList hasChanged={hasChanged} />
      </div>
      <ProductFormData updateProducts={updateProducts} />
      <Footer />
    </>
  );
}

export default App;
