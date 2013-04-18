class AddPasswordToUsers < ActiveRecord::Migration
  def change
    add_column :users, :password_digest_string, :string
  end
end
