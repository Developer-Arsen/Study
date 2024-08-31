import React, { useEffect, useState } from "react";
import Product from "./Product";

const apiUrl = `${window.location.origin}/products`;

const ProductsList = ({ hasChanged }) => {
    const [products, setProducts] = useState([]);

    useEffect(() => {
        async function fetchData() {
            try {
                let response = await fetch(apiUrl);
                response = await response.json();
                setProducts(response?.data);
            } catch (error) {
                console.error('Error fetching data:', error);
            }
        }
        fetchData();
    }, [hasChanged])

    return (
        <div id="productList" className="row row-cols-1 row-cols-sm-2 row-cols-md-3 row-cols-lg-4">
            {products?.map(product => <Product key={product._id} product={product} />)}
        </div>
    );
};

export default ProductsList;