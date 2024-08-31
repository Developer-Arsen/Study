import React, { useEffect, useState } from "react"

const Product = ({ product }) => {
    const [wasm, setWasm] = useState();

    return (
        <div className="col mb-4" key={product._id}>
            <div className="card product-card">
                <div className="img-div">
                    <img src={product.url} className="card-img-top" alt="{product.name}" />
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