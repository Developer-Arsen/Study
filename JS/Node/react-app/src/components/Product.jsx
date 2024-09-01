import React from "react";
import axios from "axios";

const protocol = window.location.protocol;
const hostname = window.location.hostname;
const protocolAndHostname = `${protocol}//${hostname}`;
const deleteProduct = protocolAndHostname + ":3006/products/";

const Product = ({ updateProducts, product }) => {

    const deleteItem = async (id) => {
        await axios.delete(deleteProduct + id);
        updateProducts();
    }

    return (
        <div className="col mb-4">
            <div className="card product-card">
                <p onClick={() => deleteItem(product._id)} style={{ cursor: "pointer", color: "red", position: 'absolute', right: '10px', top: '10px' }} title="delete">X</p>
                <div className="img-div">
                    <img src={product.url} className="card-img-top" alt={product.name} />
                </div>
                <div className="card-body">
                    <p className="product-title">{product.name}</p>
                    <p className="product-price">{product.price}$</p>
                </div>
            </div>
        </div>
    )
}

export default Product;
