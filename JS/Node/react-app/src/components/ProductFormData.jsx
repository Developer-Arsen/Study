import React from "react";
import { useForm } from "react-hook-form";
import axios from "axios";

const protocol = window.location.protocol;
const hostname = window.location.hostname;
const protocolAndHostname = `${protocol}//${hostname}`;
const addProduct = protocolAndHostname + ":3006/products";

const ProductFormData = ({ updateProducts }) => {
    const { register, handleSubmit, formState: { errors } } = useForm();

    const onSubmit = async (data) => {
        const formData = new FormData();

        formData.append("image", data.image[0]);
        formData.append("name", data.name);
        formData.append("price", data.price);
        try {
            await axios.post(addProduct, formData, {
                headers: {
                    "Content-Type": "multipart/form-data"
                }
            });
            updateProducts();
        } catch (error) {
            console.error("There was an error adding the product:", error);
        }
    };

    return (
        <div className="container product-form-container">
            <h3>Add New Product</h3>
            <form onSubmit={handleSubmit(onSubmit)} id="productForm">
                <div className="mb-3">
                    <label htmlFor="name" className="form-label">Product Name</label>
                    <input type="text" className="form-control" id="name" {...register("name", { required: "Name is required" })} />
                    {errors.name && <p className="text-danger">{errors.name.message}</p>}
                </div>
                <div className="mb-3">
                    <label htmlFor="price" className="form-label">Product Price</label>
                    <input type="number" className="form-control" id="price" {...register("price", { required: "Price is required" })} />
                    {errors.price && <p className="text-danger">{errors.price.message}</p>}
                </div>
                <div className="mb-3">
                    <label htmlFor="productImage" className="form-label">Product Image</label>
                    <input type="file" className="form-control" id="productImage" accept="image/*" {...register("image", { required: "Image is required" })} />
                    {errors.image && <p className="text-danger">{errors.image.message}</p>}
                </div>
                <button type="submit" className="btn btn-primary w-100">Submit</button>
            </form>
        </div>
    );
};

export default ProductFormData;
