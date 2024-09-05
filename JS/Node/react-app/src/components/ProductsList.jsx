import React, { useEffect, useState } from "react";
import Product from "./Product";
import { Link } from "react-router-dom";

const protocol = window.location.protocol;
const hostname = window.location.hostname;
const protocolAndHostname = `${protocol}//${hostname}`;
const productsFetch = protocolAndHostname + ":3006/products";

const ProductsList = ({ hasChanged, updateProducts }) => {
    const [products, setProducts] = useState([]);
    const [fetchProducts, setFetchProducts] = useState(false);

    const update = () => {
        setFetchProducts(!fetchProducts);
    }

    useEffect(() => {
        async function fetchData() {
            try {
                let response = await fetch(productsFetch);
                response = await response.json();
                setProducts(response?.data);
            } catch (error) {
                console.error('Error fetching data:', error);
            }
        }
        fetchData();
    }, [hasChanged, fetchProducts])

    return (
        <div id="productList" className="row row-cols-1 row-cols-sm-2 row-cols-md-3 row-cols-lg-4">
            {products?.map(product => {
                return (
                    <Link to={`/products/${product._id}`} style={{textDecoration: "None", color: "inherit"}}>
                        <Product updateProducts={update} key={product._id} product={product} />
                    </Link>
                )
            })}
        </div>
    );
};

export default ProductsList;
