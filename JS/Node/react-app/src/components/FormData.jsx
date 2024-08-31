import React from "react";
import { useForm } from "react-hook-form"
import axios from "axios";


const apiUrl = `${window.location.origin}/products`;

const FormData = ({updatePorducts}) => {
    const { register, handleSubmit, formState: { errors } } = useForm();

    const onSubmit = async (data) => {
        try {
            const response = await axios.post(apiUrl, data, {
                headers: {
                    "Content-Type": "application/json"
                }
            });
            console.log("Product added successfully:", response.data);
            updatePorducts();
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
                    <label htmlFor="url" className="form-label">Product Image Url</label>
                    <input type="text" className="form-control" id="url" {...register("url", { required: "Url is required" })} />
                    {errors.url && <p className="text-danger">{errors.url.message}</p>}
                </div>
                {/* <div className="mb-3">
                    <label htmlFor="productImage" className="form-label">Product Image</label>
                    <input type="file" className="form-control" id="productImage" accept="image/*" required>
                </div> */}
                <button type="submit" className="btn btn-primary w-100">Submit</button>
            </form>
        </div>
    );
};

export default FormData;