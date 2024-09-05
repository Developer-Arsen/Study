import React, { useState } from "react";
import Footer from "./Footer";
import ProductsList from "./ProductsList";
import ProductFormData from "./ProductFormData";

const Products = () => {
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

export default Products;
